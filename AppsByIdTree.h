/****************************************************************************/
/*                                                                          */
/* AppsByIdTree class header                                                */
/*                                                                          */
/****************************************************************************/

#ifndef _234218_WET1_APPS_BY_ID_TREE_H_
#define _234218_WET1_APPS_BY_ID_TREE_H_

#include "AVLTree.h"
#include "common.h"


class AppsByIdTree: public AVLTree< int, AppData* > {
public:
    // Adds an app to the data structue
    // Time complexity: O(log(n)) where n is the number of apps in the tree
    // Throws NullArgumentException if appData is null
    // Throws DuplicateNodeException if an appwith the provided id already
    // exists
    void addApp(const AppData* appData);

    // Removes an app from the data structue
    // Time complexity: O(log(n)) where n is the number of apps in the tree
    // Throws ElementNotFoundException if an app with the provided id was not
    // found
    void removeApp(int appId);

    // Finds a node with the given appId and returns it
    // Time complexity: O(log(n)) where n is the number of apps in the tree
    // Throws ElementNotFoundException if an app with the provided id was not
    // found
    AppData** getAppById(int appId) const;

private:
    /**
     * Abstract predicate function for comparing a search key and a data instance.
     * Must be overriden to enable searching, insertion and removal from the tree.
     * @return 1 if key > data, -1 if key < data and 0 if both are considered equal
     */
    virtual int predKeyData(const int& key, const AppData* data) const;

    /**
     * Abstract predicate function for comparing two data instance.
     * Must be overriden to enable insertion and removal from the tree.
     * @return 1 if data > other, -1 if data < other and 0 if both are equal
     */
    virtual int predDataData(const AppData* data, const AppData* other) const;
};

#endif    /* _234218_WET1_APPS_BY_ID_TREE_H_ */
