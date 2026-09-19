// 1000ef10 RwTransformBegin [Global]
// programa: RWL21.DLL

bool __fastcall RwTransformBegin(undefined4 param_1,int param_2)

{
  int iVar1;
  
                    /* 0xef10  505  RwTransformBegin */
  iVar1 = FUN_1001d760(param_1,param_2);
  return (bool)('\x01' - (iVar1 == 0));
}


