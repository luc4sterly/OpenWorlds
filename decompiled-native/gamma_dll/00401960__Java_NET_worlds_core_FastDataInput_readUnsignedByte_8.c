// 00401960 _Java_NET_worlds_core_FastDataInput_readUnsignedByte@8 [Global]
// program: gamma.dll

undefined1 _Java_NET_worlds_core_FastDataInput_readUnsignedByte_8(int *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_d;
  
                    /* 0x1960  132  _Java_NET_worlds_core_FastDataInput_readUnsignedByte@8 */
  iVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  if (*(int *)(iVar2 + 8) < 1) {
    if (*(int *)(iVar2 + 0xc) == 0) {
      *(char **)(iVar2 + 0xc) = s_java_io_EOFException_0046d18c;
      *(char **)(iVar2 + 0x10) = s_EOF_Error_0046d1a4;
    }
  }
  else {
    puVar1 = *(undefined1 **)(iVar2 + 4);
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
    local_d = *puVar1;
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
  }
  if (*(byte **)(iVar2 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10));
  }
  return local_d;
}


