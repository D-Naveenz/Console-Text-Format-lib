# ----------------------------------------------------------------------------------
# Header functions
# ----------------------------------------------------------------------------------
function HeaderTopNBottom {
    $string = "# "
    for ($i = 0; $i -lt $Host.UI.RawUI.BufferSize.Width - 4; $i++) {
        $string = $string + "-"
    }
    $string = $string + " #"

    return $string
}

function HeaderBlankLine {
    $string = "# "
    for ($i = 0; $i -lt $Host.UI.RawUI.BufferSize.Width - 4; $i++) {
        $string = $string + " "
    }
    $string = $string + " #"
    return $string
}

function HeaderCenterText {
    param($Message)

    $string = "# "

    for ($i = 0; $i -lt (([Math]::Max(0, $Host.UI.RawUI.BufferSize.Width / 2) - [Math]::Max(0, $Message.Length / 2))) - 4; $i++) {
        $string = $string + " "
    }

    $string = $string + $Message

    for ($i = 0; $i -lt ($Host.UI.RawUI.BufferSize.Width - ((([Math]::Max(0, $Host.UI.RawUI.BufferSize.Width / 2) - [Math]::Max(0, $Message.Length / 2))) - 2 + $Message.Length)) - 2; $i++) {
        $string = $string + " "
    }

    $string = $string + " #"
    return $string

}

# ----------------------------------------------------------------------------------
# Build functions
# ----------------------------------------------------------------------------------
function BuilW32 {
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

    Write-Output "Generating Static Library..."
    Set-Location $Lib
    ar rcs libcontf.a *.o

    # delete temp files
    Write-Output "Removing redundant files..."
    Remove-Item *.o

    Write-Output "Done!"
    Write-Output ""
}

function BuilW64 {
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

    Write-Output "Generating Static Library..."
    Set-Location $Lib
    ar rcs libcontf64.a *.o

    # delete temp files
    Write-Output "Removing redundant files..."
    Remove-Item *.o

    Write-Output "Done!"
    Write-Output ""
}

function BuildPause ($Message = "Press any key to continue...") {
    # Check if running in PowerShell ISE
    If ($psISE) {
        # "ReadKey" not supported in PowerShell ISE.
        # Show MessageBox UI
        $Shell = New-Object -ComObject "WScript.Shell"
        # $Button = $Shell.Popup("Click OK to continue.", 0, "Hello", 0)
        $Shell.Popup("Click OK to continue.", 0, "Hello", 0)
        Return
    }
  
    $Ignore =
    16, # Shift (left or right)
    17, # Ctrl (left or right)
    18, # Alt (left or right)
    20, # Caps lock
    91, # Windows key (left)
    92, # Windows key (right)
    93, # Menu key
    144, # Num lock
    145, # Scroll lock
    166, # Back
    167, # Forward
    168, # Refresh
    169, # Stop
    170, # Search
    171, # Favorites
    172, # Start/Home
    173, # Mute
    174, # Volume Down
    175, # Volume Up
    176, # Next Track
    177, # Previous Track
    178, # Stop Media
    179, # Play
    180, # Mail
    181, # Select Media
    182, # Application 1
    183  # Application 2
  
    Write-Host -NoNewline $Message
    While ($Null -eq $KeyInfo.VirtualKeyCode -or $Ignore -contains $KeyInfo.VirtualKeyCode) {
        $KeyInfo = $Host.UI.RawUI.ReadKey("NoEcho, IncludeKeyDown")
    }
}