// 100630e0 FUN_100630e0 [Global]
// program: RWDL8D21.DLL

undefined8 __fastcall
FUN_100630e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_4 + 0x10) = *(undefined1 *)(param_3 + 0x10);
  *(undefined1 *)((int)param_4 + 0x41) = 1;
  uVar1 = param_3[1];
  *param_4 = *param_3;
  param_4[1] = uVar1;
  uVar1 = param_3[4];
  param_4[2] = param_3[2];
  param_4[4] = uVar1;
  uVar1 = param_3[6];
  param_4[5] = param_3[5];
  param_4[6] = uVar1;
  uVar1 = param_3[9];
  param_4[8] = param_3[8];
  param_4[9] = uVar1;
  uVar1 = param_3[0xc];
  param_4[10] = param_3[10];
  param_4[0xc] = uVar1;
  uVar1 = param_3[0xe];
  param_4[0xd] = param_3[0xd];
  param_4[0xe] = uVar1;
  uVar1 = param_3[7];
  param_4[3] = param_3[3];
  param_4[7] = uVar1;
  uVar1 = param_3[0xf];
  param_4[0xb] = param_3[0xb];
  param_4[0xf] = uVar1;
  return CONCAT44(param_2,param_4);
}


