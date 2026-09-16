// 004067e0 FUN_004067e0 [Global]
// programa: gamma.dll

undefined4 * __thiscall
FUN_004067e0(int *param_1,undefined4 *param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined2 uVar1;
  undefined4 uStack_10;
  
  uVar1 = *(undefined2 *)(param_4 + 0x30);
  *(ushort *)(param_4 + 0x30) = *(ushort *)(param_4 + 0x30) & 0xffb5;
  *(ushort *)(param_4 + 0x30) = *(ushort *)(param_4 + 0x30) | 8;
  *(ushort *)(param_4 + 0x30) = *(ushort *)(param_4 + 0x30) | 0x200;
  *(ushort *)(param_4 + 0x30) = *(ushort *)(param_4 + 0x30) & 0xff4f;
  *(ushort *)(param_4 + 0x30) = *(ushort *)(param_4 + 0x30) | 0x10;
  *(undefined4 *)(param_4 + 0x2c) = 10;
  (**(code **)(*param_1 + 0xc))(&uStack_10,param_3,param_4,param_5,param_6);
  *param_2 = uStack_10;
  *(undefined2 *)(param_4 + 0x30) = uVar1;
  return param_2;
}


