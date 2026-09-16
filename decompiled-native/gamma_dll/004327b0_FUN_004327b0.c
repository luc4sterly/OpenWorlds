// 004327b0 FUN_004327b0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_004327b0(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined4 auStack_18 [4];
  
  puVar1 = FUN_0042f9f0();
  FUN_004295a0(auStack_18,*(float *)(param_1 + 0x94),(int)puVar1);
  FUN_00428cd0(param_2,param_1 + 0x54,(int)auStack_18);
  return param_2;
}


