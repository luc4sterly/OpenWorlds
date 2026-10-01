// 004041e1 FUN_004041e1 [Global]
// program: gdkup.exe

void __fastcall FUN_004041e1(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 in_EAX;
  int unaff_EBX;
  
  *(undefined4 *)(param_2 + 0x10) = 2;
  *(int *)(param_2 + 0x14) = unaff_EBX;
  uVar1 = *(undefined4 *)(unaff_EBX + 9);
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x18) = uVar1;
  *(undefined4 *)(param_2 + 0xc) = in_EAX;
  *(int *)(param_2 + 4) = param_2 + 0x10;
  FUN_00405aa0(in_EAX,param_2 + 0x10);
  return;
}


