[<img src="https://user-images.githubusercontent.com/28660469/227711535-03fd1d77-1fad-4e00-9703-57e4a85180ed.png" width=100 align="right" >](https://epflrocketteam.ch/)

# XSTRATO RF Protocol Interface
<img src="https://user-images.githubusercontent.com/28660469/227712654-80d11d6f-1579-4451-bb96-b4893685d71e.png" width=100 align="left">

This repository should be used as a **git submodule** for the RF interface such as packet definition.
The goal is to minimize the protocol interface difficulties encountered between the subsystems & boards.
By having this git submodule repository shared between subsystems, no more interface documents are required as a git pull would be sufficient to be updated.

___________________________________________________________
### How to clone the repository with submodules
```
git clone --recurse-submodules https://github.com/MorgesHAB/XSTRATO.git
```
___________________________________________________________
### How to set up the git submodule in your code ?
Follow this [link](https://git-scm.com/book/en/v2/Git-Tools-Submodules) or directly the instructions below.

Go in your main project folder, which is alreay a git repository, and run:
```
git submodule add https://github.com/EPFLRocketTeam/ERT_RF_Protocol_Interface.git
```
By default, it will create a folder name "ERT_RF_Protocol_Interface". You can add a different path at the end of the command if you want it to go elsewhere.

Then in your C++ code, you can simply do:
```cpp
#include <XRF_interface/PacketDefinition.h>
```
Now you can have access to the *struct* definitions in your code, see the [example](#how-to-properly-use-packet-structure) at the end. 

### How to get the last modifications ?
You will need to run git pull but from the submodule directory
```
git pull
```

### How to push code to it ?
Once you made some modifications to the code of this submodule, you need to go in the submodule folder (ERT_RF_Protocol_Interface), then you can run `git status` to see if some changes are seen. If yes you need to add this files, commit with a message and finally push.
```
git add --all
git commit -m "uplink packet update"
git push
```
Note that as it is a private repository, you will need to connect to your account. You can read the next [section](#how-to-create-a-github-token-) for more infos.