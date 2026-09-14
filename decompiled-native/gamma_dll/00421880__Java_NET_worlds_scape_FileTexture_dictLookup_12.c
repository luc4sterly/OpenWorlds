// 00421880 _Java_NET_worlds_scape_FileTexture_dictLookup@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_FileTexture_dictLookup_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  
                    /* 0x21880  228  _Java_NET_worlds_scape_FileTexture_dictLookup@12 */
  if (DAT_0049d168 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_FileTexture_00471310);
    DAT_0049d168 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_0049d168 == 0) {
      FUN_00402800(s_nFileTexture_00471330,0x26);
    }
    DAT_0049d16c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d168,s__urlName_00471354,s_Ljava_lang_String__00471340
                             );
    DAT_0049d170 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d168,s_textureID_00471364,&DAT_00471360);
    DAT_0049d174 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049d168,s_<init>_00471374,&DAT_00471370);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049d16c != 0) && (DAT_0049d170 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049d174 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nFileTexture_00471330,0x2c);
    }
  }
  pcVar4 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar5 = FUN_00421420(pcVar4,0,0);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar4);
  if (iVar5 != 0) {
    uVar3 = FUN_00415a40(param_1,DAT_0049d168,DAT_0049d174);
    (**(code **)(*param_1 + 0x1b4))(param_1,uVar3,DAT_0049d170,iVar5);
    (**(code **)(*param_1 + 0x1a0))(param_1,uVar3,DAT_0049d16c,param_3);
    return uVar3;
  }
  return 0;
}


