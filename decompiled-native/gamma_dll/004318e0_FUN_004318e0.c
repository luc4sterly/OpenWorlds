// 004318e0 FUN_004318e0 [Global]
// program: gamma.dll

void __cdecl FUN_004318e0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  float local_64 [16];
  undefined4 local_24 [5];
  
  if (param_1 == 0) {
    return;
  }
  FUN_00428df0(local_24,param_3);
  FUN_00429070((int)local_24);
  FUN_00429050(local_24,local_64);
  uVar1 = FUN_00419950();
  FUN_00419f90(uVar1,local_64);
  FUN_00419f50(uVar1,3,0,*(undefined4 *)(param_2 + 4));
  FUN_00419f50(uVar1,3,1,*(undefined4 *)(param_2 + 8));
  FUN_00419f50(uVar1,3,2,*(undefined4 *)(param_2 + 0xc));
  FUN_00418bc0(param_1,uVar1);
  FUN_004198f0();
  FUN_00428e50(local_24);
  return;
}


