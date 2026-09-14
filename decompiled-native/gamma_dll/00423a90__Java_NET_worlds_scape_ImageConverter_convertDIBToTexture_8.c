// 00423a90 _Java_NET_worlds_scape_ImageConverter_convertDIBToTexture@8 [Global]
// programa: gamma.dll

int _Java_NET_worlds_scape_ImageConverter_convertDIBToTexture_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined8 uVar6;
  
                    /* 0x23a90  236  _Java_NET_worlds_scape_ImageConverter_convertDIBToTexture@8 */
  uVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049d1b8);
  pcVar2 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,uVar1,0);
  iVar3 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1b4);
  iVar4 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1b0);
  iVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1ac);
  uVar6 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1a4);
  iVar3 = FUN_004222b0(extraout_ECX,(int)((ulonglong)uVar6 >> 0x20),(HGDIOBJ)uVar6,iVar5,iVar4,iVar3
                       ,pcVar2,0);
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar1,pcVar2);
  return iVar3;
}


