// 00406e91 FUN_00406e91 [Global]
// program: gdkup.exe

undefined4 __fastcall FUN_00406e91(undefined4 param_1,char *param_2)

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
  FUN_00406e47(param_2,pcVar1);
  return extraout_ECX;
}


