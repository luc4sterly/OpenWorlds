// 004235c0 _Java_NET_worlds_scape_ScapePicMovie_lookupTextures@24 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_ScapePicMovie_lookupTextures_24
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
               undefined4 param_6)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
                    /* 0x235c0  278  _Java_NET_worlds_scape_ScapePicMovie_lookupTextures@24 */
  puVar1 = (undefined4 *)FUN_00450b60(param_4 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00402800(s_nScapePicTexture_004713c4,599);
  }
  puVar4 = puVar1;
  for (iVar3 = param_4 * 4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  pcVar2 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  uVar5 = 0;
  if (0 < param_4) {
    do {
      iVar3 = FUN_00421420(pcVar2,0,uVar5);
      puVar1[uVar5] = iVar3;
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < param_4);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar2);
  FUN_00423420(param_1,param_2,puVar1,param_4,param_5,param_6);
  return;
}


