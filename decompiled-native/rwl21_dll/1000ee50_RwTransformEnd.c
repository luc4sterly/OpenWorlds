// 1000ee50 RwTransformEnd [Global]
// program: RWL21.DLL

bool RwTransformEnd(void)

{
  int iVar1;
  
                    /* 0xee50  511  RwTransformEnd */
  iVar1 = FUN_1001d780();
  return (bool)('\x01' - (iVar1 == 0));
}


