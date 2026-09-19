// 100044a0 RwGetClumpTag [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpTag(int param_1)

{
                    /* 0x44a0  167  RwGetClumpTag */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0xe8);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


