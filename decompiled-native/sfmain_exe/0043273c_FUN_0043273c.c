// 0043273c FUN_0043273c [Global]
// program: sfmain.exe

int __fastcall FUN_0043273c(int param_1,int param_2)

{
  char *in_EAX;
  char cVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  int iVar4;
  
  if (param_2 < 0) {
    cVar1 = '-';
    param_2 = -param_2;
  }
  else {
    cVar1 = '+';
  }
  iVar3 = 100;
  iVar2 = 3;
  if (param_2 < 100) {
    iVar3 = 10;
    iVar2 = 2;
    if (param_2 < 10) {
      iVar2 = 1;
      iVar3 = 1;
    }
  }
  if ((unaff_EBX == 0) && (unaff_EBX = 2, iVar2 == 3)) {
    unaff_EBX = 3;
  }
  iVar4 = unaff_EBX + 1;
  if (iVar4 <= param_1) {
    if (unaff_EBX < iVar2) {
      iVar4 = iVar2 + 1;
    }
    else {
      *in_EAX = cVar1;
      for (; in_EAX = in_EAX + 1, iVar2 < unaff_EBX; unaff_EBX = unaff_EBX + -1) {
        *in_EAX = '0';
      }
      do {
        *in_EAX = (char)(param_2 / iVar3) + '0';
        param_2 = param_2 % iVar3;
        iVar3 = iVar3 / 10;
        in_EAX = in_EAX + 1;
      } while (iVar3 != 0);
    }
  }
  return iVar4;
}


