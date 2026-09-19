// 10045270 _qsort [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _qsort
   
   Library: Visual Studio 1998 Release */

void __cdecl
_qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *local_f8;
  int local_f4;
  undefined4 auStack_f0 [30];
  int aiStack_78 [30];
  
  if ((_NumOfElements < 2) || (_SizeOfElements == 0)) {
    return;
  }
  local_f4 = 0;
  local_f8 = (undefined1 *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
LAB_100452af:
  uVar1 = (uint)((int)local_f8 - (int)_Base) / _SizeOfElements + 1;
  if (8 < uVar1) {
    swap((undefined1 *)((int)_Base + (uVar1 >> 1) * _SizeOfElements),_Base,_SizeOfElements);
    puVar3 = local_f8 + _SizeOfElements;
    puVar4 = _Base;
LAB_10045310:
    puVar4 = puVar4 + _SizeOfElements;
    if (puVar4 <= local_f8) goto code_r0x10045318;
    goto LAB_10045328;
  }
  shortsort(_Base,local_f8,_SizeOfElements,_PtFuncCompare);
  goto LAB_100452d6;
code_r0x10045318:
  iVar2 = (*_PtFuncCompare)(puVar4,_Base);
  if (iVar2 < 1) goto LAB_10045310;
LAB_10045328:
  do {
    puVar3 = puVar3 + -_SizeOfElements;
    if (puVar3 <= _Base) break;
    iVar2 = (*_PtFuncCompare)(puVar3,_Base);
  } while (-1 < iVar2);
  if (puVar4 <= puVar3) {
    swap(puVar4,puVar3,_SizeOfElements);
    goto LAB_10045310;
  }
  swap(_Base,puVar3,_SizeOfElements);
  if ((int)(puVar3 + (-1 - (int)_Base)) < (int)local_f8 - (int)puVar4) {
    if (puVar4 < local_f8) {
      auStack_f0[local_f4] = puVar4;
      aiStack_78[local_f4] = (int)local_f8;
      local_f4 = local_f4 + 1;
    }
    if ((undefined1 *)((int)_Base + _SizeOfElements) < puVar3) {
      local_f8 = puVar3 + -_SizeOfElements;
      goto LAB_100452af;
    }
  }
  else {
    if ((undefined1 *)((int)_Base + _SizeOfElements) < puVar3) {
      auStack_f0[local_f4] = _Base;
      aiStack_78[local_f4] = (int)puVar3 - _SizeOfElements;
      local_f4 = local_f4 + 1;
    }
    _Base = puVar4;
    if (puVar4 < local_f8) goto LAB_100452af;
  }
LAB_100452d6:
  local_f4 = local_f4 + -1;
  if (local_f4 < 0) {
    return;
  }
  local_f8 = (undefined1 *)aiStack_78[local_f4];
  _Base = (undefined1 *)auStack_f0[local_f4];
  goto LAB_100452af;
}


