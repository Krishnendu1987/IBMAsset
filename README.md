# IBMAsset

## Description of the Asset:-
This asset is a part enhancement of IBM owned ETL tool Datastage for easing out a transformation using regular expression. As we know regex [regular expression] is big tool for cleansing , validation and transformation of unstructured data into a regular set but unfortunately Datastage as of now provide this facility inherently so we go for this enhancement using a parallel routine.
[NOTE: This Asset is not to be strictly made in public since this is an IBM internal property and already commercialized. So no public repository like GitHub upload has been done. ]

## Benefits of this Asset:- 
Using this asset you have the following benefit
*	Portability :- You can use it in any project using datastage irrespective of much change to the code.
*	Flexibility :- You can use this routine and tweak it as per your requirement.
*	Usability :- Any kind of regex rule validation and regex match find can be done using routine.

## Installation

Well the above code you need to place under /home/dsadm directory and give chmod 777 permission to the files. Then you need to run the below command to do the compilation.
g++ -c -O -fPIC -Wno-deprecated -m64 -mtune=generic -mcmodel=small checkRegularExpression.cpp
g++ -c -O -fPIC -Wno-deprecated -m64 -mtune=generic -mcmodel=small checkRegularExpressionMatch.cpp
chmod 777 checkRegularExpression.o
chmod 777 checkRegularExpressionMatch.o


## Utility:-
Now you can use any expression instead of our above example [0-9]+ using this routine to take out your correct data from any unstructured unformatted text. This function can be used as an enhanced “Field()” function of Datastage as well if you want to find out a delimiter which is a regular expression.
So from overall utility perspective this asset is very useful and generic. 
