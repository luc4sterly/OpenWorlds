// 004264f0 _Java_NET_worlds_scape_Transform_getGuts@8 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_scape_Transform_getGuts_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 local_50 [16];
  
                    /* 0x264f0  316  _Java_NET_worlds_scape_Transform_getGuts@8 */
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00419740(uVar2,local_50);
  uVar2 = (**(code **)(*param_1 + 0x2d4))(param_1,0x10);
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x2f4))(param_1,uVar2,0);
  iVar5 = 0;
  iVar6 = 0;
  puVar4 = puVar3;
  do {
    iVar5 = iVar5 + 1;
    *puVar4 = local_50[iVar6];
    puVar4[1] = local_50[iVar6 + 1];
    puVar4[2] = local_50[iVar6 + 2];
    iVar1 = iVar6 + 3;
    iVar6 = iVar6 + 4;
    puVar4[3] = local_50[iVar1];
    puVar4 = puVar4 + 4;
  } while (iVar5 < 4);
  (**(code **)(*param_1 + 0x314))(param_1,uVar2,puVar3,0);
  return uVar2;
}


