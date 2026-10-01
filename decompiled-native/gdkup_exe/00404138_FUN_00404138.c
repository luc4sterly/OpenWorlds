// 00404138 FUN_00404138 [Global]
// program: gdkup.exe

undefined4 __fastcall FUN_00404138(undefined4 param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (DAT_00408dd8 != '\0') {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)(param_2);
    return uVar2;
  }
  return 0;
}


