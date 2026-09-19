// 100512f4 rwFixMul [Global]
// programa: RWL21.DLL

/* rwFixMul */

undefined8 __cdecl rwFixMul(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 in_EDX;
  int iVar3;
  
                    /* 0x512f4  537  _rwFixMul */
  lVar1 = (longlong)param_1 * (longlong)param_2;
  iVar3 = (int)((ulonglong)lVar1 >> 0x20);
  uVar2 = (uint)lVar1 >> 0x10 | iVar3 << 0x10;
  if ((iVar3 != (short)((ulonglong)lVar1 >> 0x20)) &&
     (uVar2 = 0x7fffffff, (char)((ulonglong)lVar1 >> 0x28) < '\0')) {
    uVar2 = 0x80000000;
  }
  return CONCAT44(in_EDX,uVar2);
}


