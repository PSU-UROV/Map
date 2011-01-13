#!/usr/bin/sh
#so...make is retarded and can't have colons in it's command parameters
#apparently

#so instead of a make file you get a shell script

cc=dmcs #use the Cs 4 compiler
references=System.Runtime.Serialization #add the necessary references
                    #note, this needs to be improved substantially.There
                    #are better ways of getting references to a project
target=library


$cc /t:$target /r:$references Vector.cs VectorList.cs
