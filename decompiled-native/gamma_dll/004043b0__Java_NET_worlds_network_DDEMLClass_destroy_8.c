// 004043b0 _Java_NET_worlds_network_DDEMLClass_destroy@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_network_DDEMLClass_destroy_8(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
                    /* 0x43b0  178  _Java_NET_worlds_network_DDEMLClass_destroy@8 */
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048907c);
  if (puVar3 != (undefined4 *)0x0) {
    if (puVar3[4] != 0) {
      DdeDisconnect((HCONV)*puVar3);
      DdeFreeStringHandle(DAT_004a0430,(HSZ)puVar3[1]);
      DdeFreeStringHandle(DAT_004a0430,(HSZ)puVar3[2]);
      puVar1 = (undefined4 *)0x0;
      for (puVar2 = DAT_0049fcc0; puVar2 != puVar3; puVar2 = (undefined4 *)puVar2[5]) {
        puVar1 = puVar2;
      }
      if (puVar2 != puVar3) {
        FUN_00402800(s_nDDEMLClass_0046d590,0xa2);
      }
      if (puVar3 == DAT_0049fcb8) {
        DAT_0049fcb8 = puVar1;
      }
      if (puVar1 == (undefined4 *)0x0) {
        DAT_0049fcc0 = (undefined4 *)DAT_0049fcc0[5];
      }
      else {
        puVar1[5] = *(undefined4 *)(puVar1[5] + 0x14);
      }
    }
    FUN_0044e100(puVar3);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0048907c,0);
  return;
}


