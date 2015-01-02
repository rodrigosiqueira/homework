/**
*	@file
*	@author
*	@author
*	@author
* @brief
**/
#include <asm/page.h>
#include <linux/mm.h>
#include <linux/fs.h>

#include "../inc/virtualMemoryOperation.h"
/**
*	@var
*	@brief
*/
static struct vm_operations_struct virtualMemoryOperations = 
{
	.open 	= virtualMemoryOpen,
	.close	= virtualMemoryClose,
	.fault	=	virtualMemoryFault,
};

static int * share_mem;

int * allocSharedMemory()
{
	share_mem = (int *)vmalloc(PAGE_SIZE);
	return share_mem;
}

void freeSharedMemory()
{
	vfree(share_mem);
}

int * getSharedMemory()
{
	return share_mem;
}

void virtualMemoryOpen(struct vm_area_struct * _vma)
{
	printk(KERN_NOTICE "Virual: %lx, Physical: %lx\n", 
			_vma->vm_start, _vma->vm_pgoff << PAGE_SHIFT);
	return;
}

void virtualMemoryClose(struct vm_area_struct * _vma)
{
	printk(KERN_NOTICE "Virtual Memory close.");
	return;
}

int virtualMemoryFault(struct vm_area_struct * _vma, struct vm_fault * _vmf)
{
	struct page *page;
	unsigned long offset;
	void *page_ptr;

	printk("\nPage fault by OSP");
	printk("\n\tVirtual Memory Falut Offset: %lx", _vmf->pgoff);
	printk("\n\tVirtual Memory Fault Virtual Address: %p", _vmf->virtual_address);

	printk("\n\tstart: %lx", _vma->vm_start);
	printk("\n\tend: %lx", _vma->vm_end);
	printk("\n\tVirtual Memory offset: %lx", _vma->vm_pgoff);

	page_ptr = NULL;
	//__va -> Convert virtual to physical memory address.
	if((NULL == _vma) || (NULL == share_mem))
	{
		printk("return VM_FAULT_SIGBUS!\n");
		return VM_FAULT_SIGBUS;
	}

	offset = (unsigned long)_vmf->virtual_address - _vma->vm_start;
	if(offset >= PAGE_SIZE)
	{
		printk("return VM_FAULT_SIGBUS!");
		return VM_FAULT_SIGBUS;
	}

	page_ptr = share_mem + offset;
	page = vmalloc_to_page(page_ptr);
	get_page(page);
	_vmf->page = page;

	return 0;
}

int pageMmap(struct file * _file, struct vm_area_struct * _vma)
{
	unsigned long offset = _vma->vm_pgoff << PAGE_SHIFT;

	if(offset >= __pa(high_memory) || (_file->f_flags & O_SYNC))
	{
		_vma->vm_flags |= VM_IO;
	}
	_vma->vm_flags |= (VM_IO | VM_LOCKED | (VM_DONTEXPAND | VM_DONTDUMP));

	_vma->vm_ops = &virtualMemoryOperations;
	virtualMemoryOpen(_vma);

	return 0;
}

