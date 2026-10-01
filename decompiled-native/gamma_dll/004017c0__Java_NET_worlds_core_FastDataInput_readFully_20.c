// 004017c0 _Java_NET_worlds_core_FastDataInput_readFully@20 [Global]
// program: gamma.dll

void _Java_NET_worlds_core_FastDataInput_readFully_20
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  
                    /* 0x17c0  127  _Java_NET_worlds_core_FastDataInput_readFully@20 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  iVar2 = (**(code **)(*param_1 + 0x2e0))(param_1,param_3,0);
  if (*(int *)(iVar1 + 8) < (int)param_5) {
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(char **)(iVar1 + 0xc) = s_java_io_EOFException_0046d18c;
      *(char **)(iVar1 + 0x10) = s_EOF_Error_0046d1a4;
    }
  }
  else {
    FUN_0044df50((undefined4 *)(iVar2 + param_4),*(undefined4 **)(iVar1 + 4),param_5);
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + param_5;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) - param_5;
  }
  (**(code **)(*param_1 + 0x300))(param_1,param_3,iVar2,0);
  if (*(byte **)(iVar1 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
  }
  return;
}


