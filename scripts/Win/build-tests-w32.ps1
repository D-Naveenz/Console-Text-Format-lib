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
$Tests = $WorkingDir + '\tests'
$Lib = $WorkingDir + '\lib'

# build the compiled object in the lib folder
Write-Output "Compiling test files..."
Get-ChildItem -Path $Tests -Recurse -Filter *.c |
Foreach-Object {
    $C_File = $_.Name
    if (!$C_File.StartsWith("_")) {
        $X_file = [System.IO.Path]::ChangeExtension($C_File, ".exe")
        Write-Output "Test file: $C_File -> Executable: $X_file"
        #x86_64-w64-mingw32-gcc -g $Tests\$C_File $Tests\_tests.c -I $Includes -L $Lib -lcontf -o $Tests\$X_File
        i686-w64-mingw32-gcc -g $Tests\$C_File $Tests\_tests.c -I $Includes -L $Lib -lcontf -o $Tests\$X_File
    }
}

Write-Output ""
Write-Output "Done!"

BuildPause