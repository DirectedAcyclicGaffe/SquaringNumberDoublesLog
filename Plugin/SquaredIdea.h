#ifndef SQUAREDIDEA_H
#define SQUAREDIDEA_H

#include "OneToOneIdeaTemplate.h"

struct SquaredAttributes : public IdeaAttributes
{
    SquaredAttributes();
};

class SquaredIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    explicit SquaredIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n1);
};

#endif // SQUAREDIDEA_H
