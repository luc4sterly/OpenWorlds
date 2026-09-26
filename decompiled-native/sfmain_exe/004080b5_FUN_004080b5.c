// 004080b5 FUN_004080b5 [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_004080b5(undefined4 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *in_EAX;
  int unaff_EBX;
  
  do {
    unaff_EBX = unaff_EBX + -1;
    if (unaff_EBX == -1) {
      return 0;
    }
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
    cVar2 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 == cVar2);
  return 1;
}


