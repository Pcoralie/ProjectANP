##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=project
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Utilisateur/Documents/ESILV/S8/advancedNetworkProgramming/TD4/TD4Network
ProjectPath            :=C:/Users/Utilisateur/Documents/ESILV/S8/advancedNetworkProgramming/ProjectANP
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Utilisateur
Date                   :=13/03/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="project.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  -lws2_32 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/client.c$(ObjectSuffix) $(IntermediateDirectory)/server.c$(ObjectSuffix) $(IntermediateDirectory)/TCP_client.c$(ObjectSuffix) $(IntermediateDirectory)/UDP_client.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/client.c$(ObjectSuffix): client.c $(IntermediateDirectory)/client.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Utilisateur/Documents/ESILV/S8/advancedNetworkProgramming/ProjectANP/client.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/client.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/client.c$(DependSuffix): client.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/client.c$(ObjectSuffix) -MF$(IntermediateDirectory)/client.c$(DependSuffix) -MM client.c

$(IntermediateDirectory)/client.c$(PreprocessSuffix): client.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/client.c$(PreprocessSuffix) client.c

$(IntermediateDirectory)/server.c$(ObjectSuffix): server.c $(IntermediateDirectory)/server.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Utilisateur/Documents/ESILV/S8/advancedNetworkProgramming/ProjectANP/server.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/server.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/server.c$(DependSuffix): server.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/server.c$(ObjectSuffix) -MF$(IntermediateDirectory)/server.c$(DependSuffix) -MM server.c

$(IntermediateDirectory)/server.c$(PreprocessSuffix): server.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/server.c$(PreprocessSuffix) server.c

$(IntermediateDirectory)/TCP_client.c$(ObjectSuffix): TCP_client.c $(IntermediateDirectory)/TCP_client.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Utilisateur/Documents/ESILV/S8/advancedNetworkProgramming/ProjectANP/TCP_client.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TCP_client.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TCP_client.c$(DependSuffix): TCP_client.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TCP_client.c$(ObjectSuffix) -MF$(IntermediateDirectory)/TCP_client.c$(DependSuffix) -MM TCP_client.c

$(IntermediateDirectory)/TCP_client.c$(PreprocessSuffix): TCP_client.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TCP_client.c$(PreprocessSuffix) TCP_client.c

$(IntermediateDirectory)/UDP_client.c$(ObjectSuffix): UDP_client.c $(IntermediateDirectory)/UDP_client.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Utilisateur/Documents/ESILV/S8/advancedNetworkProgramming/ProjectANP/UDP_client.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UDP_client.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UDP_client.c$(DependSuffix): UDP_client.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UDP_client.c$(ObjectSuffix) -MF$(IntermediateDirectory)/UDP_client.c$(DependSuffix) -MM UDP_client.c

$(IntermediateDirectory)/UDP_client.c$(PreprocessSuffix): UDP_client.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UDP_client.c$(PreprocessSuffix) UDP_client.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


