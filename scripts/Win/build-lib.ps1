# ----------------------------------------------------------------------------------
# Build functions
# ----------------------------------------------------------------------------------
function BuidlW32 {
    [CmdletBinding()]
    param(
        [Alias('s')]
        $Source,
        [Alias('l')]
        $Lib,
        [Alias('i')]
        $Include
    )

    # build the compiled object in the lib folder
    Write-Output "Compiling source files..."
    Get-ChildItem -Path $Source -Recurse -Filter *.c |
    Foreach-Object {
        $C_File = $_.FullName
        $O_file = [System.IO.Path]::ChangeExtension($Lib + "\" + $_.Name, ".o")
        gcc -m32 -g -c $C_File -I $Include -o $O_File
    }
}

function BuildW64 {
    [CmdletBinding()]
    param(
        [Alias('s')]
        $Source,
        [Alias('l')]
        $Lib,
        [Alias('i')]
        $Include
    )

    # build the compiled object in the lib folder
    Write-Output "Compiling source files..."
    Get-ChildItem -Path $Core -Recurse -Filter *.c |
    Foreach-Object {
        $C_File = $_.FullName
        $O_file = [System.IO.Path]::ChangeExtension($Lib + "\" + $_.Name, ".o")
        gcc -m64 -g -c $C_File -I $Includes -o $O_File
    }
}

# ----------------------------------------------------------------------------------
# Main Script
# ----------------------------------------------------------------------------------

# Some applications like VSCode run ps scripts on Workspace Directory. But if we use native powershell console,
# the PWD is the same directory which ps scripts stored.
if ($PWD.Path.Contains("\scripts\Win")) {
    # Import core.ps1
    . $PWD\core.ps1
    Set-Location ..\..\
}
else {
    # Import core.ps1
    . $PWD\scripts\Win\core.ps1
}

$H_TopBottom = HeaderTopNBottom
$H_Blank = HeaderBlankLine

# print the header
$H_TopBottom
$H_Blank
HeaderCenterText "Console Text Formatter library builder tool"
HeaderCenterText "v1.2"
$H_Blank
$H_TopBottom
Write-Output "Initializing..."

# Set directory paths
$WorkingDir = $PWD.Path
$Includes = $WorkingDir + '\include'
$Core = $WorkingDir + '\core'
$Lib = $WorkingDir + '\lib'

# create lib folder if doesn't exist
[void](New-Item -Path $Lib -ItemType Directory -Force)

# check minGW version
if (IsGCC64) {
    Write-Output "MinGW GCC 64bit compiler detected."
    Write-Output ""
    # Build 64bit windows lib
    Write-Output ">> Building 64 bit library"
    BuildW64 -s $Core -l $Lib -i $Includes
}
else {
    Write-Output "MinGW GCC 32bit compiler detected."
    Write-Output ""
    # Build 32bit windows lib
    Write-Output ">> Building 32 bit library"
    BuildW32 -s $Core -l $Lib -i $Includes
}

Write-Output "Generating Static Library..."
Set-Location $Lib
ar rcs libcontf.a *.o

# delete temp files
Write-Output "Removing redundant files..."
Remove-Item *.o

Write-Output "Done!"
Write-Output ""

BuildPause
