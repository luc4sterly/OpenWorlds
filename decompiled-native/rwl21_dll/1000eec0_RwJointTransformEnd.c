// 1000eec0 RwJointTransformEnd [Global]
// programa: RWL21.DLL

bool RwJointTransformEnd(void)

{
  int iVar1;
  
                    /* 0xeec0  286  RwJointTransformEnd */
  iVar1 = FUN_1001d720(DAT_1005dfd0);
  return (bool)('\x01' - (iVar1 == 0));
}


