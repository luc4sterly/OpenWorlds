// 004028cf FUN_004028cf [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_004028cf(undefined4 param_1,char *param_2)

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
  FUN_00402885(param_2,pcVar1);
  return extraout_ECX;
}


