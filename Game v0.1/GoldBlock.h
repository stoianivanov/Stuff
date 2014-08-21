#ifndef GOLDBLOCK_H
#define GOLDBLOCK_H

#include "Block.h"
#include "Gold.h"

class GoldBlock : public Block
{
public:
	GoldBlock(char);

	virtual bool activate(Game &);
	virtual GoldBlock* clone() const;

private:
	/// ����� ���������� ����� � ���� ��
	Gold gold;
};


#endif // GOLDBLOCK_H INCLUDED
