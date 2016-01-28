#ifndef TAG_HOLDER
#define TAG_HOLDER
#include <set>

using namespace std;
class TagHolder
{
public:
    enum Tag
    {
        Nanobot_type,
        Projectile,
    };

    TagHolder();
    ~TagHolder();

    bool HasTag(Tag tag);
protected:
    void AddTag(Tag tag);
private:
    set<Tag> setOfTags;
};

#endif // TAG_HOLDER
