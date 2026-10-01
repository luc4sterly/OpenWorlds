// 00423920 _Java_NET_worlds_scape_ImageConverter_setDIBPixelBytes@36 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_ImageConverter_setDIBPixelBytes_36
               (int *param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int param_6,
               undefined4 param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
                    /* 0x23920  239  _Java_NET_worlds_scape_ImageConverter_setDIBPixelBytes@36 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1ac);
  uVar2 = iVar1 + 3U & 0xfffffffc;
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1a8);
  puVar5 = (undefined4 *)(param_4 * uVar2 + iVar1 + param_3);
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x2e0))(param_1,param_7,0);
  iVar1 = 0;
  puVar4 = puVar3;
  if (0 < param_6) {
    do {
      FUN_0044df50(puVar5,puVar4,param_5);
      iVar1 = iVar1 + 1;
      puVar5 = (undefined4 *)((int)puVar5 + uVar2);
      puVar4 = (undefined4 *)((int)puVar4 + param_9);
    } while (iVar1 < param_6);
  }
  (**(code **)(*param_1 + 0x300))(param_1,param_7,puVar3,0);
  return;
}


