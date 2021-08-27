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

# ----------------------------------------------------------------------------------
# Main Script
# ----------------------------------------------------------------------------------

$H_TopBottom = HeaderTopNBottom
$H_Blank = HeaderBlankLine

# print the header
$H_TopBottom
$H_Blank
HeaderCenterText "Console Text Formatter library builder tool"
HeaderCenterText "v1.1"
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
Write-Output ""

# Build 32bit windows lib
Write-Output ">> Building 32 bit library"
BuilW32 -s $Core -l $Lib -i $Includes

# Build 32bit windows lib
Write-Output ">> Building 64 bit library"
BuilW64 -s $Core -l $Lib -i $Includes

BuildPause
