#include "CMatrix.h"
#include "CMatrix.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include "stdarg.h"
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <time.h>
using namespace std;



/*

[ Function Name ] : isInsideMatrix()
[ Returned Type ] : int
[ inherited Function from CMatrix Class ] : getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
[ Functionality ] : To Get the Index of Parameter Matrix inside the Matrix vector so we can get the index
                    and use the matrix in this index anywhere else

*/

int isInsideMatrix(vector<CMatrix> matricesArray,string target) {
        bool found = false;
        int index = -1;
        for(int i =0;i < matricesArray.size();i++) {
                if(matricesArray[i].getName() == target) {
                        found = true;
                        index = i;
                }
        }
        return index;

}

/* ############################################################################# */
/*

[ Function Name ] : addOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - + Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make addOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/

CMatrix addOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix returnedResult = matricesArray[a] + matricesArray[b];
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : subOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - - Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make subOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/


CMatrix subOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix returnedResult = matricesArray[a] - matricesArray[b];
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : multiplyOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - * Operator - [ Inside File : CMatrix.cpp , Line : 318 ] ==> uses += & add Function in the Same File
[ Functionality ] : To Make multiplyOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/

CMatrix multiplyOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix returnedResult = matricesArray[a] * matricesArray[b];
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : addOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - getInverse() - [ Inside File : CMatrix.cpp , Line : 532 ]
                                                - * Operator - [ Inside File : CMatrix.cpp , Line : 318 ]
[ Functionality ] : To Make divideOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/
CMatrix divideOperation(vector<CMatrix> matricesArray,int a,int b,string target) {
        CMatrix aMatrix = matricesArray[a];
        CMatrix bMatrix = matricesArray[b].getInverse();
        CMatrix returnedResult = aMatrix * bMatrix;
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ Function Name ] : transposeOperation
[ Returned Type ] : CMatrix
[ inherited Function or Operators from CMatrix Class ] :
                                                - getName() - [ Inside File : CMatrix.cpp , Line : 167 ]
                                                - getTranspose() - [ Inside File : CMatrix.cpp , Line : 522 ]
[ Functionality ] : To Make addOperation to Two Matrices we just pass the whole matrices vector and indeces of the two target matrices,
                    and return a matrix that have the result

*/


CMatrix transposeOperation(vector<CMatrix> &matricesArray,int a,string target) {
        CMatrix returnedResult = matricesArray[a].getTranspose();
        returnedResult.setName(target);
        return returnedResult;

}
/* ############################################################################# */

/*

[ function name] : elementWiseDivOperationNumber
[ return type] : CMatrix
[ inherited function/operation ] : -getnR() [CMatrix.cpp, line: ]
                                   -getnC() [CMatrix.cpp, line: ]
                                   -elementWiseDiv() [CMatrix.cpp, line: ]
                                   -setName() [CMatrix.cpp, line: ]
[ functionality ] : converts the first parameter (that is number) of type string to float and constructs a full matrix with it,
                    then performs element wise division with the second parameter (that is a matrix given by the user)

*/

CMatrix elmentWiseDivOperationNumber(vector<CMatrix> &matricesArray,int a,string number,string target) {

        int num = atof(number.c_str());
        CMatrix aMatrix = matricesArray[a];
        CMatrix dMatrix(aMatrix.getnR(),aMatrix.getnC(),CMatrix::MI_VALUE,num);
        CMatrix returnedResult = dMatrix.elementWiseDiv(aMatrix);
        returnedResult.setName(target);
        return returnedResult;

}

/* ############################################################################# */

/*

[ function name] : elementWiseDivOperationNormal
[ return type] : CMatrix
[ inherited function/operation ] : -elementWiseDiv() [CMatrix.cpp, line: ]
                                                      -setName() [CMatrix.cpp, line: ]
[ functionality ] : performs element wise division with the first and second parameters (that are matrices given by the user)

*/

CMatrix elmentWiseDivOperationNormal(vector<CMatrix> &matricesArray,int a,int b,string target) {

        CMatrix aMatrix = matricesArray[a];
        CMatrix bMatrix = matricesArray[b];
        CMatrix returnedResult = bMatrix.elementWiseDiv(aMatrix);
        returnedResult.setName(target);
        return returnedResult;

}


/* ############################################################################# */

/*

[ function name] : checkAlpha
[ return type] : bool
[ inherited function/operation ] : none
[ functionality ] : checks if the string parameter is a number

*/

bool checkNumeric(const string &str) {
	bool allDigits = true;
	for (int i = 0; i < str.size(); i++)
		if (!isdigit(str[i]) && str[i] != '.')
				allDigits = false;
	return allDigits;
}

/* ############################################################################# */

void programLoopFromFile(char* fileName){

          vector<CMatrix> matrices;

  std::ifstream ifs( fileName );
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
  (std::istreambuf_iterator<char>()    ) );

  size_t countSqaures = std::count(content.begin(),content.end() , ']');
  bool flag = false;

  for(int i = 0 ;i < countSqaures + 1;i++) {

          size_t found = content.find('[');
          if(found != std::string::npos) {
          string matrixData,matrixName;
          matrixData = content.substr(0,content.find(']') + 1);
          matrixName = matrixData.substr(0,content.find('='));
          matrixName.erase(std::remove(matrixName.begin(),matrixName.end(),' '),matrixName.end());
          matrixData.erase(0,matrixData.find('['));
          matrixData.erase(std::remove(matrixData.begin(), matrixData.end(), '\n'), matrixData.end());


          CMatrix temp(matrixName,matrixData);
          matrices.push_back(temp);
          int indexOfSemicolon = content.find(']') + 1;
          if(content[indexOfSemicolon] != ';') {
                  cout << temp.getName() << " = " << endl;
                  cout << temp;
                  cout << "######################################################" << endl;
          }
          content.erase(0,content.find('=',content.find(']')) - 2);

          } else {
                  flag = true;
          }

  }



  std::istringstream f(content);
  std::string operationLine;
  int countMe = 0;
  while(getline(f,operationLine)) {
          if(operationLine.find('+') != std::string::npos) {
              operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
              string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('+') - (operationLine.find('=') + 1));
              string secondParameter = operationLine.substr(operationLine.find('+') + 1);
              string result = operationLine.substr(0,operationLine.find('='));

              CMatrix resultMatrix = addOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
              matrices.push_back(resultMatrix);

              if(operationLine.find(';') == std::string::npos) {
                      cout << resultMatrix.getName() << " = " << endl;
                      cout << resultMatrix;
                      cout << "######################################################" << endl;
                      
              }

          }
          else if(operationLine.find('-') != std::string::npos) {
          operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

              string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('-') - (operationLine.find('=') + 1));
              string secondParameter = operationLine.substr(operationLine.find('-') + 1);
              string result = operationLine.substr(0,operationLine.find('='));

              CMatrix resultMatrix = subOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
              matrices.push_back(resultMatrix);
              
              if(operationLine.find(';') == std::string::npos) {
                      cout << resultMatrix.getName() << " = " << endl;
                      cout << resultMatrix;
                      cout << "######################################################" << endl;
              
              }

          }
          else if(operationLine.find('*') != std::string::npos) {
          operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

              string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('*') - (operationLine.find('=') + 1));
              string secondParameter = operationLine.substr(operationLine.find('*') + 1);
              string result = operationLine.substr(0,operationLine.find('='));

              CMatrix resultMatrix = multiplyOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
              matrices.push_back(resultMatrix);

              if(operationLine.find(';') == std::string::npos) {
                      cout << resultMatrix.getName() << " = " << endl;
                      cout << resultMatrix;
                      cout << "######################################################" << endl;
              
              }

          }

          else if(operationLine.find("./") != std::string::npos) {
            operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

            string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find("./") - (operationLine.find('=') + 1));
            string secondParameter = operationLine.substr(operationLine.find("./") + 2);
            string result = operationLine.substr(0,operationLine.find('='));

            if(checkNumeric(firstParameter)) {

              CMatrix resultMatrix = elmentWiseDivOperationNumber(matrices,isInsideMatrix(matrices,secondParameter),firstParameter,result);
              matrices.push_back(resultMatrix);

              if(operationLine.find(';') == std::string::npos) {
                      cout << resultMatrix.getName() << " = " << endl;
                      cout << resultMatrix;
                      cout << "######################################################" << endl;
              
              }

            } else {
              CMatrix resultMatrix = elmentWiseDivOperationNormal(matrices,isInsideMatrix(matrices,secondParameter),isInsideMatrix(matrices,firstParameter),result);
              matrices.push_back(resultMatrix);

              if(operationLine.find(';') == std::string::npos) {
                      cout << resultMatrix.getName() << " = " << endl;
                      cout << resultMatrix;
                      cout << "######################################################" << endl;
              
              }

            }


          }

          else if(operationLine.find('/') != std::string::npos && operationLine.find('.') == std::string::npos) {
          operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());

              string firstParameter = operationLine.substr(operationLine.find('=') + 1, operationLine.find('/') - (operationLine.find('=') + 1));
              string secondParameter = operationLine.substr(operationLine.find('/') + 1);
              string result = operationLine.substr(0,operationLine.find('='));

              int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
              CMatrix secondParameterTemp = matrices[secondParameterIndex].getInverse();
              if(secondParameterTemp.getName() == "Invert" || secondParameterTemp.getnC() != secondParameterTemp.getnR()) {
                      cout << "This Operation Can't Be Made Because [ " << secondParameter << " ] Can't Be Inverted" << endl;
                      cout << "######################################################" << endl;
              
              } else {
                CMatrix resultMatrix = divideOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                matrices.push_back(resultMatrix);
                if(operationLine.find(';') == std::string::npos) {
                        cout << resultMatrix.getName() << " = " << endl;
                        cout << resultMatrix;
                        cout << "######################################################" << endl;
                
                }
              }



          }
          else if(operationLine.find("'") != std::string::npos) {
                  operationLine.erase(std::remove(operationLine.begin(), operationLine.end(), ' '), operationLine.end());
                  string firstParameter = operationLine.substr(operationLine.find('=') + 1,1);
                  string result = operationLine.substr(0,operationLine.find('='));

                  CMatrix resultMatrix = transposeOperation(matrices,isInsideMatrix(matrices,firstParameter),result);
                  matrices.push_back(resultMatrix);

                  if(operationLine.find(';') == std::string::npos) {
                      cout << resultMatrix.getName() << " = " << endl;
                      cout << resultMatrix;
                      cout << "######################################################" << endl;
              
              }

          }



  } // End Of While

} // End of Program Function




int main(int argc, char* argv[]){

                      if (argc > 1) {

                        programLoopFromFile(argv[1]);
                      }
                      else {
                      vector<CMatrix> matrices;

                        string s;
                        string line;
                        string semicolonCheck;
                        while(1) {
                          getline(cin, s);

                          if(s.find('[') != string::npos && s.find(']') == string::npos ) {
                              getline(cin,line, ']');
                              string name = "";
                              name += s[0];
                              CMatrix temp(name, line);
                              matrices.push_back(temp);


                                getline(cin ,semicolonCheck);
                                if(semicolonCheck == "") {
                                        cout << temp.getName() << " = " << endl;
                                        cout << temp;
                                        cout << "######################################################" << endl;
                                        
                                } else if(semicolonCheck == ";"){
                                        semicolonCheck = "";
                                }

                          } else if(s.find('[') != string::npos && s.find(']') != string::npos){
                              string name = s.substr(0 , s.find('='));
                              name.erase(std::remove(name.begin(),name.end(),' '),name.end());
                              size_t found = s.find('[');
                              string matrixData,matrixName;
                              if(found != std::string::npos) {
                                matrixData = s.substr(0,s.find(']') + 1);
                                matrixData.erase(0,matrixData.find('['));
                                matrixData.erase(std::remove(matrixData.begin(), matrixData.end(), '\n'), matrixData.end());
                              }
                              CMatrix temp(name , matrixData);
                              matrices.push_back(temp);
                              
                                if(s.find(';' , s.find(']')) != std::string::npos) {
                                        semicolonCheck = "";
                              } else {
                                      cout << temp.getName() << " = " << endl;
                                      cout << temp;
                                      cout << "######################################################" << endl;
                        
                              }




                          } else if(s.find('[') == string::npos && s.find(']') == string::npos && s.find("=") != string::npos) {
                            if(s.find('+') != std::string::npos) {
                                s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
                                string firstParameter = s.substr(s.find('=') + 1, s.find('+') - (s.find('=') + 1));
                                string secondParameter = s.substr(s.find('+') + 1);
                                string result = s.substr(0,s.find('='));
                                if(s.find(';') == std::string::npos) {
                                        CMatrix resultMatrix = addOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                        matrices.push_back(resultMatrix);
                                        cout << resultMatrix.getName() << " = " << endl;
                                        cout << resultMatrix;
                                        cout << "######################################################" << endl;
                                        

                                } else {
                                        CMatrix resultMatrix = addOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                        matrices.push_back(resultMatrix);
                                }

                            }
                            else if(s.find('-') != std::string::npos) {
                            s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                                string firstParameter = s.substr(s.find('=') + 1, s.find('-') - (s.find('=') + 1));
                                string secondParameter = s.substr(s.find('-') + 1);
                                string result = s.substr(0,s.find('='));

                                if(s.find(';') == std::string::npos) {
                                        CMatrix resultMatrix = subOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                        matrices.push_back(resultMatrix);
                                        cout << resultMatrix.getName() << " = " << endl;
                                        cout << resultMatrix;
                                        cout << "######################################################" << endl;
                        
                                } else {
                                        CMatrix resultMatrix = subOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                        matrices.push_back(resultMatrix);

                                }

                            }
                            else if(s.find('*') != std::string::npos) {
                            s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                                string firstParameter = s.substr(s.find('=') + 1, s.find('*') - (s.find('=') + 1));
                                string secondParameter = s.substr(s.find('*') + 1);
                                string result = s.substr(0,s.find('='));

                                if(s.find(';') == std::string::npos) {
                                        CMatrix resultMatrix = multiplyOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                        matrices.push_back(resultMatrix);
                                        cout << resultMatrix.getName() << " = " << endl;
                                        cout << resultMatrix;
                                        cout << "######################################################" << endl;

                                } else {
                                        CMatrix resultMatrix = multiplyOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                        matrices.push_back(resultMatrix);

                                }

                            }

                            else if(s.find("./") != std::string::npos) {
                              s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                              string firstParameter = s.substr(s.find('=') + 1, s.find("./") - (s.find('=') + 1));
                              string secondParameter = s.substr(s.find("./") + 2);
                              string result = s.substr(0,s.find('='));

                              if(checkNumeric(firstParameter)) {

                                CMatrix resultMatrix = elmentWiseDivOperationNumber(matrices,isInsideMatrix(matrices,secondParameter),firstParameter,result);
                                matrices.push_back(resultMatrix);

                                if(s.find(';') == std::string::npos) {
                                        cout << resultMatrix.getName() << " = " << endl;
                                        cout << resultMatrix;
                                        cout << "######################################################" << endl;

                                }

                              } else {
                                CMatrix resultMatrix = elmentWiseDivOperationNormal(matrices,isInsideMatrix(matrices,secondParameter),isInsideMatrix(matrices,firstParameter),result);
                                matrices.push_back(resultMatrix);
                                
                                if(s.find(';') == std::string::npos) {
                                        cout << resultMatrix.getName() << " = " << endl;
                                        cout << resultMatrix;
                                        cout << "######################################################" << endl;

                                }

                              }


                            }

                            else if(s.find('/') != std::string::npos && s.find('.') == std::string::npos) {
                                s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

                                string firstParameter = s.substr(s.find('=') + 1, s.find('/') - (s.find('=') + 1));
                                string secondParameter = s.substr(s.find('/') + 1);
                                string result = s.substr(0,s.find('='));

                                int secondParameterIndex = isInsideMatrix(matrices,secondParameter);
                                CMatrix secondParameterTemp = matrices[secondParameterIndex].getInverse();
                                if(secondParameterTemp.getName() == "Invert" || secondParameterTemp.getnC() != secondParameterTemp.getnR()) {
                                        cout << "This Operation Can't Be Made Because [ " << secondParameter << " ] Can't Be Inverted" << endl;
                                } else {
                                        if(s.find(';') == std::string::npos) {
                                                CMatrix resultMatrix = divideOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                                matrices.push_back(resultMatrix);
                                                cout << resultMatrix.getName() << " = " << endl;
                                                cout << resultMatrix;
                                                cout << "######################################################" << endl;

                                        } else {
                                                CMatrix resultMatrix = divideOperation(matrices,isInsideMatrix(matrices,firstParameter),isInsideMatrix(matrices,secondParameter),result);
                                                matrices.push_back(resultMatrix);
                                        }
                                }

                            }
                            else if(s.find("'") != std::string::npos) {
                                s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
                                string firstParameter = s.substr(s.find('=') + 1,1);
                                string result = s.substr(0,s.find('='));

                                if(s.find(';') == std::string::npos) {
                                        CMatrix resultMatrix = transposeOperation(matrices,isInsideMatrix(matrices,firstParameter),result);
                                        matrices.push_back(resultMatrix);
                                        cout << resultMatrix.getName() << " = " << endl;
                                        cout << resultMatrix;
                                        cout << "######################################################" << endl;
        
                                } else {
                                        CMatrix resultMatrix = transposeOperation(matrices,isInsideMatrix(matrices,firstParameter),result);
                                        matrices.push_back(resultMatrix);
                                }



                            }


                          } else if(s.find("=") == string::npos && s != "") {
                            int matrixIndex = isInsideMatrix(matrices,s);
                            if(matrixIndex == -1) {
                              cout << "Uninitialized Matrix" << endl;

                            } else {
                              cout << matrices[matrixIndex];
                              cout << "###################################" << endl;

                            }

                          }

                        }

                }

                /* ########################################## */
                /* Test Cases */
                //       string s = "[8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 8.6 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.6 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.8 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9;8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.9 8.9 7.3 4.8 2.4 2.3 6.5 8.9 1.2 4.9 3.8 7.2 7.5 9.8 3.4 7.5 8.8;];";
                // string s2 = "[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;1 1 1 1 1 1 1 1 1 1 1 1 1 1 1;]";
                // clock_t tStart = clock();
                // string s3 = "[8.9 7.3 4.0 2.4; 2.3 6.5 8.9 3.1; 4.9 3.8 2 7.5; 9.8 3.4 1 8.9]";
                // string s4 = "[1.2 5.7 4.2 1.4; 6.3 2.5 8.1 3.1; 6.4 2.8 7.1 8.1; 3.2 5.1 7.2 8.9]";
                //       CMatrix n("D",s3);
                //       CMatrix t("T",s4);

                //       CMatrix temp = t.getInverse();

                //       cout << "Division in Exampel.m File" << endl;

                //       if(temp.getName() == "Invert") {
                //               cout << "Matrix Can't Be Invertable" << endl;
                //       } else {
                //               cout << "Matrix is invertable" << endl;
                //               CMatrix result = n * temp;
                //               result.setName("A");
                //               cout << "Result of Division of A and B in Example.m : " << endl;
                //               cout << result;

                //       }


                //       cout << "**************************************" << endl;
                //       cout << "Matrix in bigexample.m" << endl;
                //       CMatrix y("K",s);
                //       cout << "Number of Rows : " << y.getnR() << endl;
                //       cout << "Number of Columns : " << y.getnC() << endl;
                //       cout << "Value of Determinant : " << y.getDeterminant() << endl;

                //       CMatrix temp2 = y.getInverse();

                //       if(temp2.getName() == "Invert") {
                //               cout << "Matrix is Not Invertable" << endl;
                //       } else {

                //               cout << "Matrix is Invertable" << endl;

                //               cout << temp << endl;
                //       }



                //       cout << "#################### Execution Time ###################" << endl;
                //       cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;



				return 0;
}
