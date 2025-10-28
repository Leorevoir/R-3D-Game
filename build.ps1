#!/usr/bin/env pwsh

$GREEN = "`e[1;32m"
$RED = "`e[1;31m"
$ILC = "`e[3m"
$ORG = "`e[1;33m"
$RST = "`e[0m"

$PROGRAM_NAME = "r-gwent"

function Write-Error-Exit
{
    param(
        [string]$Message,
        [string]$Detail
    )
    Write-Host "${RED}[❌] ERROR:`n${RST}`t$Message`n`t${ILC}`"$Detail`"${RST}" -NoNewline
    Write-Host ""
    exit 84
}

function Write-Success
{
    param([string]$Message)
    Write-Host "${GREEN}[✅] SUCCESS:`t${RST} ${ILC}$Message${RST}"
}

function Write-Info
{
    param([string]$Message)
    Write-Host "${ORG}[🚧] RUNNING:`t${RST} ${ILC}$Message${RST}"
}

function Invoke-BaseRun
{
    param(
        [string]$CmakeArgs,
        [string]$BuildType
    )

    & git submodule update --init --recursive

    if (-not (Test-Path "build")) {
        New-Item -ItemType Directory -Path "build" -Force | Out-Null
    }

    Push-Location "build"
    if (-not $?) {
        Write-Error-Exit "mkdir failed" "failed to create build directory"
    }

    try {
        & cmake .. -G Ninja $CmakeArgs.Split(' ')
        if ($LASTEXITCODE -ne 0) {
            throw "cmake failed"
        }

        & ninja $BuildType.Split(' ')
        if ($LASTEXITCODE -ne 0) {
            Write-Error-Exit "compilation error" "failed to compile $BuildType"
        }

        Write-Success "compiled $BuildType"
    }
    finally {
        Pop-Location
    }
}

function Invoke-All
{
    Invoke-BaseRun "-DCMAKE_BUILD_TYPE=Release -DENABLE_DEBUG=OFF" $PROGRAM_NAME
    exit 0
}

function Invoke-Debug
{
    Invoke-BaseRun "-DCMAKE_BUILD_TYPE=Debug -DENABLE_DEBUG=ON" $PROGRAM_NAME
    exit 0
}

function Invoke-Clean
{
    if (Test-Path "build") {
        Remove-Item -Recurse -Force "build"
    }
}

function Invoke-FClean
{
    Invoke-Clean

    $itemsToRemove = @(
        "$PROGRAM_NAME.exe",
        "r-engine.exe",
        "r-engine",
        "plugins",
        "code_coverage.txt",
        "cmake-build-debug"
    )

    foreach ($item in $itemsToRemove) {
        if (Test-Path $item) {
            Remove-Item -Recurse -Force $item
        }
    }

    Get-ChildItem -Path "." -Filter "vgcore*" -ErrorAction SilentlyContinue | Remove-Item -Force
    Get-ChildItem -Path "." -Filter "*.a" -ErrorAction SilentlyContinue | Remove-Item -Force
    Get-ChildItem -Path "." -Filter "libr*" -ErrorAction SilentlyContinue | Remove-Item -Force
}

function Show-Help
{
    $scriptName = $MyInvocation.ScriptName
    if (-not $scriptName) { $scriptName = "build.ps1" }

    Write-Host @"
USAGE:
      $scriptName    builds $PROGRAM_NAME project

ARGUMENTS:
      $scriptName [-h|-help|--help]    displays this message
      $scriptName [-d|-debug|--debug]  debug flags compilation
      $scriptName [-c|-clean|--clean]  clean the project
      $scriptName [-f|-fclean|--fclean] fclean the project
      $scriptName [-r|-re|--re]        fclean then build all
"@
}

if ($args.Count -eq 0) {
    Invoke-All
    exit 0
}

foreach ($arg in $args) {
    switch -Regex ($arg) {
        "^(-h|--help)$" {
            Show-Help
            exit 0
        }
        "^(-c|--clean)$" {
            Invoke-Clean
            exit 0
        }
        "^(-f|--fclean)$" {
            Invoke-FClean
            exit 0
        }
        "^(-d|--debug)$" {
            Invoke-Debug
        }
        "^(-r|--re)$" {
            Invoke-FClean
            Invoke-All
        }
        default {
            Write-Error-Exit "Invalid arguments: " "$arg"
        }
    }
}
