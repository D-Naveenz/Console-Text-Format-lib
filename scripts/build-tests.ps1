# Go back to the workspace folder. If you are using vscode, Don't do this operation! 
Set-Location ..\

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
    $X_file = [System.IO.Path]::ChangeExtension($C_File, ".exe")
    Write-Output "Test file: $C_File -> Executable: $X_file"
    x86_64-w64-mingw32-gcc -g $Tests\$C_File -I $Includes -L $Lib -lcontf -o $Tests\$X_File
}

Write-Output ""
Write-Output "Done!"
Pause