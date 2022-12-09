# Dog Dash
### Epic Gamers

Using SFML with C++, this is our game dev project.

To read more about our design and brainstorming phase, and to look at the non-code artifacts for our project, check out our [Wiki](https://github.com/Lunatic-Labs/Demo1_EpicGamers/wiki/Dog-Dash-Design)!

You can check out our official landing page [here](bit.ly/dog-dash-game)-- see if  you can break the High Score record for Dog Dash!

# How to Play Our Game
## Option 1- Running as an .exe file
1. Download the [DogDashGame](https://github.com/Lunatic-Labs/Demo1_EpicGamers/raw/AlexBranch/DogDashGame.zip) file
2. Unzip
3. Run DogDash.exe

## Option 2- Manually Building the Game
### Windows
1. Download [Visual Studio Community](https://visualstudio.microsoft.com/downloads/)
2. Run the Visual Studio Community installer, and make sure you select the "Desktop development with C++" add-on from the installation options.
3. After the Visual Studio installation is complete, use Visual Studio to clone our repository (https://github.com/Lunatic-Labs/Demo1_EpicGamers), which will add our Visual Studio project to your projects list.
4. Next, go ahead and open the Visual Studio project. You'll come back to this soon.
5. After that, download the [SFML libraries](https://www.sfml-dev.org/download/sfml/2.5.1/). This download should be the "Visual C++ 15 (2017) - 64-bit" option for version 2.5.1 of SFML.
6. After downloading, unzip the new SFML folder, enter the "bin" folder inside, and copy all 11 of these .dll files-- they will go into the root folder of the Visual Studio project. 
7. Switch back to the Visual Studio project. You can easily find its root folder by right clicking the Solution in the Solution Explorer and then clicking "Open Folder in File Explorer." After opening this folder, paste the 11 .dll files there.

![image](https://user-images.githubusercontent.com/79927828/205941309-585f5ec5-f7e6-404a-9f3c-d59f04e05bc9.png)

8. Finally, simply open the Visual Studio project and click the "Local Windows Debugger" button at the top to run the code.

### MacOS
Coming soon. Support for SFML on MacOS is spotty, requiring a more in-depth solution.
