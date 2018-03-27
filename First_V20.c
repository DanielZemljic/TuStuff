#include <stdio.h>

int _nmbinput = 0; //Handles the + sign position in stdin

char c; //Stores the Value given from Standard Input
int X; //Stores the Last Value from the Stack
int buffer[15]; //buffer to store binary numbers
int i = 0;  //Variable to fill the buffer
int l = 0;  //Variables for the output to stdout
int m = 0;
int _tmpvar = 0; //Usage for number manipulations
int _tmpfirstvar = 0; //Usage for number manipulations
int _quotiont = 0;  //Usage for number manipulations
char _outputbuffer[4]; //Outputbuffer to put the calculatet number to stdout

int main()
{
  while(1) //endless loop which takes input as long as 0x03(EOF) apears
  {
    c = getchar();
    if(c == EOF){
      break;
    }
    else{
//---------------------------------------------------------------------
//Add the value off X and the value from the buffer together
//---------------------------------------------------------------------
      if(c == 0x2B){
        putchar(0x2B);
        putchar(0x0A);

        if(_nmbinput == 0){
          if(i > 1){
            buffer[i-1] = 0;
            i--;
          }
        }

        X = buffer[i-1] + X;
        buffer[i-1] = X;
        buffer[i] = 0;

        if(i > 1){
          i--;
        }

        //devide X and put it on stdout
        //This returns the divided number, stored in _tmpvar
        //Source: https://stackoverflow.com/questions/203854/how-to-get-the-nth-digit-of-an-integer-with-bit-wise-operations
        _quotiont = X;
        _tmpfirstvar = X;
        do {
            //The result of a division by 10 is stored
            
            _tmpvar = ((_tmpfirstvar >> 1) + _tmpfirstvar) >> 1;
            _tmpvar = ((_tmpvar >> 4) + _tmpvar);
            _tmpvar = ((_tmpvar >> 8) + _tmpvar) >> 3;
            _quotiont = _tmpvar;

            //the result of a multiplikation by 10 is stored
            _tmpvar = ((_tmpvar << 2) + _tmpvar) << 1;

            //the result from the modulo by 10 is stored
            _tmpvar = _tmpfirstvar - _tmpvar;
            if (_tmpvar >= 10) {
		            _tmpvar = _tmpvar - 10;
		            _quotiont = _quotiont + 1;
	               }
            _tmpfirstvar = _quotiont;

            _outputbuffer[l] = _tmpvar + 0x30;
            l++;
          } while(_tmpfirstvar > 0);

          m = 0;
          l--;
          do {
              putchar(_outputbuffer[l-m]);
            m++;
          } while(m <= l);

          l = 0;
      }
//---------------------------------------------------------------------
//Add the values into the buffer and put a newlin in stdout
//---------------------------------------------------------------------
      else if(c == 0x0A){
        putchar(0x0A);
        if(_nmbinput == 1){
          buffer[i] = X;
          i++;
        }
        _nmbinput = 0;
        }
//---------------------------------------------------------------------
//Read the values 0x30- to 0x39 from stdint
//---------------------------------------------------------------------
      else{
        putchar(c);
        if(_nmbinput == 0){
          X = c - 0x30;
        }
        else{
          _tmpvar = X;
          X = X << 3;
          _tmpvar = _tmpvar << 1;
          X = X + _tmpvar;
          X = X + c - 0x30;
        }
        _nmbinput = 1; //To check if input is finished
      }
    }
  }
}
