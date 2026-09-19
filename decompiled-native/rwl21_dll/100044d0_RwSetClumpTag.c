// 100044d0 RwSetClumpTag [Global]
// programa: RWL21.DLL

int RwSetClumpTag(int param_1,undefined4 param_2)

{
                    /* 0x44d0  390  RwSetClumpTag */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0xe8) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


