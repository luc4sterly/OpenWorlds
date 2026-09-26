// 00432ce0 FUN_00432ce0 [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_00432ce0(undefined4 param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (DAT_0043eadc != '\0') {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)(param_2);
    return uVar2;
  }
  return 0;
}


