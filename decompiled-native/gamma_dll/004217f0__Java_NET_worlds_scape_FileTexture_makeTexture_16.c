// 004217f0 _Java_NET_worlds_scape_FileTexture_makeTexture@16 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_FileTexture_makeTexture_16
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x217f0  229  _Java_NET_worlds_scape_FileTexture_makeTexture@16 */
  pcVar1 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar2 = (**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  iVar3 = FUN_00421420(pcVar1,iVar2,0);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d170,iVar3);
  (**(code **)(*param_1 + 0x1a0))(param_1,param_2,DAT_0049d16c,param_3);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,iVar2);
  return;
}


