// 004239d0 _Java_NET_worlds_scape_ImageConverter_setDIBPixelInts@36 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_ImageConverter_setDIBPixelInts_36
               (int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
               undefined4 param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
                    /* 0x239d0  240  _Java_NET_worlds_scape_ImageConverter_setDIBPixelInts@36 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1ac);
  iVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1a8);
  puVar5 = (undefined4 *)(param_4 * iVar1 + iVar2 + param_3);
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x2ec))(param_1,param_7,0);
  iVar2 = 0;
  if (0 < param_6) {
    puVar4 = puVar3;
    do {
      FUN_0044df50(puVar5,puVar4,param_5 << 2);
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + param_9;
      puVar5 = (undefined4 *)((int)puVar5 + iVar1);
    } while (iVar2 < param_6);
  }
  (**(code **)(*param_1 + 0x30c))(param_1,param_7,puVar3,0);
  return;
}


