// 10015d90 RwSetAxisAlignment [Global]
// program: RWL21.DLL

bool RwSetAxisAlignment(int param_1)

{
  int iVar1;
  
                    /* 0x15d90  365  RwSetAxisAlignment */
  iVar1 = RwSetClumpAxisAlignment(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),param_1);
  return (bool)('\x01' - (iVar1 == 0));
}


