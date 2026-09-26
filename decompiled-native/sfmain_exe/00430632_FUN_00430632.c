// 00430632 FUN_00430632 [Global]
// programa: sfmain.exe

char * __fastcall FUN_00430632(undefined4 param_1,int param_2)

{
  char cVar1;
  char *in_EAX;
  
  *(undefined1 *)(param_2 + 0x14) = 0;
  do {
    cVar1 = *in_EAX;
    if (cVar1 == '-') {
      *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) | 8;
    }
    else if (cVar1 == '#') {
      *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) | 1;
    }
    else if (cVar1 == '+') {
      *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) & 0xfd | 4;
    }
    else if (cVar1 == ' ') {
      if ((*(byte *)(param_2 + 0x14) & 4) == 0) {
        *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) | 2;
      }
    }
    else {
      if (cVar1 != '0') {
        return in_EAX;
      }
      *(undefined1 *)(param_2 + 0x16) = 0x30;
    }
    in_EAX = in_EAX + 1;
  } while( true );
}


