// 00401860 _Java_NET_worlds_core_FastDataInput_skipBytes@12 [Global]
// program: gamma.dll

int _Java_NET_worlds_core_FastDataInput_skipBytes_12(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
                    /* 0x1860  134  _Java_NET_worlds_core_FastDataInput_skipBytes@12 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  if (*(int *)(iVar1 + 8) < param_3) {
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(char **)(iVar1 + 0xc) = s_java_io_EOFException_0046d18c;
      *(char **)(iVar1 + 0x10) = s_EOF_Error_0046d1a4;
    }
  }
  else {
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + param_3;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) - param_3;
  }
  if (*(byte **)(iVar1 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
  }
  return param_3;
}


