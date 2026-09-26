// 100033a0 FUN_100033a0 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_100033a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)(**(code **)(DAT_100394fc + 0x34c))(0x38);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  puVar1[9] = 0;
  puVar1[0xb] = 0;
  puVar1[0xd] = 0;
  puVar2 = FUN_10003490(param_1[6],param_1[10],param_1[7],param_1[8],&DAT_10038a60);
  *puVar1 = puVar2;
  if (puVar2 == (undefined1 *)0x0) {
    (**(code **)(DAT_100394fc + 0x358))(puVar1);
    return 0;
  }
  param_1[1] = DAT_10038a6c;
  *param_1 = 2;
  param_1[2] = DAT_10038a70;
  param_1[3] = DAT_10038a74;
  param_1[4] = DAT_10038a78;
  param_1[5] = DAT_10038a7c;
  puVar4 = &DAT_10038a60;
  puVar5 = puVar1;
  for (iVar3 = 8; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
  }
  param_1[0xb] = puVar1;
  if (param_1[6] != 0) {
    (**(code **)(DAT_100394fc + 0x358))(param_1[6]);
    param_1[6] = 0;
  }
  param_1[9] = 0x10;
  return 1;
}


