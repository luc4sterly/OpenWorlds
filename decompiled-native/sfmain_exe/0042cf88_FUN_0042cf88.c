// 0042cf88 FUN_0042cf88 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0042cf88(undefined4 param_1,char *param_2)

{
  int in_EAX;
  undefined4 extraout_ECX;
  char *pcVar1;
  int unaff_EBX;
  
  pcVar1 = param_2;
  if ((unaff_EBX == 10) && (in_EAX < 0)) {
    *param_2 = '-';
    pcVar1 = param_2 + 1;
  }
  FUN_0042cf3e(param_2,pcVar1);
  return extraout_ECX;
}


