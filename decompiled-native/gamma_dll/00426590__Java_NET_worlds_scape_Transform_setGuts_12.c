// 00426590 _Java_NET_worlds_scape_Transform_setGuts@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Transform_setGuts_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_50 [16];
  
                    /* 0x26590  336  _Java_NET_worlds_scape_Transform_setGuts@12 */
  iVar2 = (**(code **)(*param_1 + 0x2ac))(param_1,param_3);
  if (iVar2 != 0x10) {
    FUN_00402800(s_nTransform_00471b9c,0x204);
  }
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x2f4))(param_1,param_3,0);
  iVar2 = 0;
  iVar6 = 0;
  puVar4 = puVar3;
  do {
    iVar2 = iVar2 + 1;
    local_50[iVar6] = *puVar4;
    local_50[iVar6 + 1] = puVar4[1];
    local_50[iVar6 + 2] = puVar4[2];
    puVar1 = puVar4 + 3;
    puVar4 = puVar4 + 4;
    local_50[iVar6 + 3] = *puVar1;
    iVar6 = iVar6 + 4;
  } while (iVar2 < 4);
  uVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00419f90(uVar5,local_50);
  (**(code **)(*param_1 + 0x314))(param_1,param_3,puVar3,0);
  return;
}


