#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static Elf64_Ehdr elf_header;
static int file;
static char *filename;

/**
 * open_file - opens file
 */

void open_file(void)
{
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		dprintf(STDERR_FILENO, "Error opening file %s\n", filename);
		exit(98);
	}
}

/**
 * close_file - closes file
 */

void close_file(void)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error closing fd %d\n", file);
		exit(98);
	}
}

/**
 * read_file - reads file
 */

void read_file(void)
{
	if (read(file, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error reading file %s\n", filename);
		close_file();
		exit(98);
	}
}

/**
 * check_elf - checks ELF file
 */

void check_elf(void)
{
	if (memcmp(elf_header.e_ident, ELFMAG, 4) != 0)
	{
		dprintf(STDERR_FILENO, "Not an ELF file\n");
		close_file();
		exit(98);
	}
}

/**
 * print_magic - prints magic numbers
 */

void print_magic(void)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_header.e_ident[i]);

		if (i < EI_NIDENT - 1)
			printf(" ");
		else
			printf("\n");
	}
}

/**
 * print_class - prints class
 */

void print_class(void)
{
	printf("  Class:                             ");

	switch (elf_header.e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header.e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints data
 */

void print_data(void)
{
	printf("  Data:                              ");

	switch (elf_header.e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header.e_ident[EI_DATA]);
	}
}

/**
 * print_version - prints version
 */

void print_version(void)
{
	printf("  Version:                           ");
	printf("%d", elf_header.e_ident[EI_VERSION]);

	if (elf_header.e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - prints osabi
 */

void print_osabi(void)
{
	printf("  OS/ABI:                            ");

	switch (elf_header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header.e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints abi
 */

void print_abi(void)
{
	printf("  ABI Version:                       ");
	printf("%d\n", elf_header.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints type
 */

void print_type(void)
{
	if (elf_header.e_ident[EI_DATA] == ELFDATA2MSB)
		elf_header.e_type >>= 8;

	printf("  Type:                              ");

	switch (elf_header.e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_header.e_type);
	}
}

/**
 * print_entry - prints entry
 */

void print_entry(void)
{
	printf("  Entry point address:               ");

	if (elf_header.e_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_header.e_entry = ((elf_header.e_entry << 8) & 0xFF00FF00) |
							 ((elf_header.e_entry >> 8) & 0xFF00FF);
		elf_header.e_entry =
			(elf_header.e_entry << 16) | (elf_header.e_entry >> 16);
	}

	if (elf_header.e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_header.e_entry);

	else
		printf("%#lx\n", elf_header.e_entry);
}

/**
 * main - prints ELF header
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 if invalid number of arguments, 98 if failure
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(1);
	}

	filename = argv[1];

	open_file();
	read_file();
	check_elf();

	printf("ELF Header:\n");
	print_magic();
	print_class();
	print_data();
	print_version();
	print_osabi();
	print_abi();
	print_type();
	print_entry();

	close_file();

	return (0);
}
