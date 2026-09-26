// 004323f4 FUN_004323f4 [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_004323f4(undefined4 param_1,char *param_2)

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
  FUN_004323aa(param_2,pcVar1);
  return extraout_ECX;
}


