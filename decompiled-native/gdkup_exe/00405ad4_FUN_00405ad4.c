// 00405ad4 FUN_00405ad4 [Global]
// programa: gdkup.exe

int __fastcall FUN_00405ad4(undefined4 param_1,int param_2)

{
  int *in_EAX;
  int iVar1;
  int extraout_ECX;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = (*(code *)**(undefined4 **)(&DAT_0040b448 + *in_EAX * 4))(param_1);
  if (*in_EAX != 2) {
    iVar1 = extraout_ECX * 8 + -8 + iVar1;
  }
  return iVar1;
}


