# print the header
Write-Output "~~~~~~~~~~~~~~~ Console Text Formatter v1.0 library builder tool ~~~~~~~~~~~~~~~"
Write-Output "Initializing..."

# Go back to the workspace folder. If you are using vscode, Don't do this operation! 
Set-Location ..\

# Set directory paths
$WorkingDir = $PWD.Path
$Includes = $WorkingDir + '\include'
$Core = $WorkingDir + '\core'
$Lib = $WorkingDir + '\lib'

# create lib folder if doesn't exist
New-Item -Path $Lib -ItemType Directory -Force
Write-Output ""
# build the compiled object in the lib folder
Write-Output "Compiling source files..."
Get-ChildItem -Path $Core -Recurse -Filter *.c |
Foreach-Object {
    $C_File = $_.FullName
    $O_file = [System.IO.Path]::ChangeExtension($Lib + "\" + $_.Name, ".o")
    x86_64-w64-mingw32-gcc -g -c $C_File -I $Includes -o $O_File
}

Write-Output "Generating Static Library..."
Set-Location $Lib
ar rcs libcontf.a *.o

# delete temp files
Write-Output "Removing redundant files..."
Remove-Item *.o

Write-Output "Done."
Write-Output ""
Pause
